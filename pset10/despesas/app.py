import os

from cs50 import SQL

from flask import Flask, flash, jsonify, json, redirect, render_template, request, session

from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"

Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///DespesasPessoaisDB.db")

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    session.clear()
    return render_template("login.html")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id

    session.clear()
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/lancamentos")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    #return apology("TODO")
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)


        # Ensure password was submitted
        elif not request.form.get("confirmation"):
            return apology("must provide confirmation", 400)

        elif request.form.get("confirmation") != request.form.get("password"):
            return apology("password and confirmation are different!", 400)


        elif request.form.get("confirmation") == request.form.get("password"):
            try:
                db.execute("INSERT INTO users (username, hash) VALUES(?, ?)",  request.form.get("username"), generate_password_hash(request.form.get("password")))
                return redirect("/login")
            except:
                return apology("User already registered!", 400)

    return render_template("register.html")

@app.route("/logout")
def logout():

    """Log user out"""

    # Forget any user_id
    session.clear()
    # Redirect user to login form
    return redirect("/")


@app.route("/categorias", methods=["GET", "POST"])
@login_required
def categorias():
    
    sql = "Select c.id, tc.descricao as tipo, c.descricao From Categoria c Inner Join TipoCategoria tc on c.idTipoCategoria = tc.id where c.idUsuario = ?;"    
    
    dados = db.execute(sql, session["user_id"])        
    
    return render_template("categorias.html", dados= dados)

@app.route("/tipoCategoria", methods=["GET", "POST"])
@login_required
def tipoCategoria():
    return render_template("tipoCategoria.html")


@app.route("/despesas", methods=["GET", "POST"])
@login_required
def despesas():
    return render_template("despesas.html")

@app.route("/despsasList", methods=["GET", "POST"])
@login_required
def despsasList():
    
    sql =   "Select d.id, d.idUsuario, c.descricao as categoria, tc.descricao as tipo, d.data, d.descricao, d.dataVencimento, d.valor  From Despesa d Inner Join Categoria c on d.idCategoria = c.id  Inner Join TipoCategoria tc on c.idTipoCategoria = tc.id  where d.idUsuario = ?;"

    dados = db.execute(sql, session["user_id"])
        
    return render_template("despsasList.html", dados=dados)

@app.route("/receitas", methods=["GET", "POST"])
@login_required
def receitas():
    return render_template("receitas.html")

@app.route("/receitasList", methods=["GET", "POST"])
@login_required
def receitasList():
    sql =   "Select r.id, r.idUsuario, r.descricao as categoria, tc.descricao as tipo, r.data, r.descricao, r.valor  From Receita r Inner Join Categoria c on r.idCategoria = c.id  Inner Join TipoCategoria tc on c.idTipoCategoria = tc.id  where r.idUsuario = ?;"

    dados = db.execute(sql, session["user_id"])

    return render_template("receitasList.html", dados=dados )

@app.route("/lancamentos", methods=["GET", "POST"])
@login_required
def lancamentos():

    dados = db.execute("Select * from lancamentos where idUsuario = ? ;", session["user_id"])

    total = db.execute("Select sum(valor)as total from lancamentos where idUsuario = ? ;", session["user_id"])
    total = total[0]
    total = round(total['total'], 3 )
    return render_template('lancamentos.html', dados=dados, total=total)