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
    dados = [{'id': '0', 'idTipoCategoria': 0, 'descricao': ''}]
    if request.method == "POST":
        idCategoria =  request.form.get("idCategoria")
        if idCategoria != '0':
            try:
                sql = "Select c.id, tc.id as idTipoCategoria, tc.descricao as tipo, c.descricao From Categoria c Inner Join TipoCategoria tc on c.idTipoCategoria = tc.id where c.idUsuario = ? and c.id = ?;"
                dados = db.execute(sql, session["user_id"], idCategoria)
                return render_template("categorias.html", dados=dados)
            except Exception as inst:
                print(type(inst))    # the exception type
                print(inst.args)     # arguments stored in .args
                print(inst)          # __str__ allows args to be printed directly,
                return {'Error' :json.dumps(inst), 'status':'400'}
        else:
            print(dados)
            return render_template("categorias.html", dados=dados)
    return render_template("categorias.html", dados=dados)

@app.route("/categoriaIncluir", methods=["GET", "POST"])
@login_required
def categoriaIncluir():
    idTipoCategoria =  request.form.get("idTipoCategoria")
    descricao = request.form.get("descricao")

    try:
        sql = "INSERT INTO Categoria (idUsuario, idTipoCategoria , descricao) VALUES  (?, ?, ? );"
        db.execute(sql,  session["user_id"], idTipoCategoria, descricao);
        jsonResponse = {"status":"200"}
        return jsonResponse

    except Exception as e:
                print(type(e))    # the exception type
                print(e.args)     # arguments stored in .args
                print(e)          # __str__ allows args to be printed directly,
                return {"Error":"Erro ao incluir categorias!", "status": "400"}

@app.route("/categoriaAlterar", methods=["GET", "POST"])
@login_required
def categoriaAlterar():
    idUsuario = session["user_id"]
    idCategoria =  request.form.get("idCategoria")
    idTipoCategoria =  request.form.get("idTipoCategoria")
    descricao = request.form.get("descricao")

    try:
        sql = "UPDATE Categoria SET idTipoCategoria = ?,  descricao = ? Where idUsuario = ? and id = ?;"
        db.execute(sql, int(idTipoCategoria), descricao, idUsuario , idCategoria );

        jsonResponse = {"idCategoria": idCategoria, "idTipoCategoria": idTipoCategoria, "descricao": descricao}
        jsonResponse = {"data": jsonResponse, "status":"200"  }
        return jsonResponse
    except Exception as inst:
                print(type(inst))    # the exception type
                print(inst.args)     # arguments stored in .args
                print(inst)          # __str__ allows args to be printed directly,
                return {"Error":"Erro ao altualizar categorias", "status": "403"}

@app.route("/categoriaDelete", methods=["GET", "POST"])
@login_required
def categoriaDelete():
    idCategoria =  request.form.get("idCategoria")
    try:
        idCategoria =  request.form.get("idCategoria")
        print(idCategoria)
        sql = "Delete  from Categoria where idUsuario = ? and id = ?;"
        db.execute(sql, session["user_id"], idCategoria)
        jsonResponse = {"status":"200", "idCategoria": idCategoria}
        return jsonResponse
    except Exception as inst:
                print(type(inst))    # the exception type
                print(inst.args)     # arguments stored in .args
                print(inst)          # __str__ allows args to be printed directly,
                return {"Error": 'Erro ao deletar categorias', "status": "403"}

@app.route("/categoriaList", methods=["GET", "POST"])
@login_required
def categoriaList():
        sql = "Select c.id, tc.descricao as tipo, c.descricao From Categoria c Inner Join TipoCategoria tc on c.idTipoCategoria = tc.id where c.idUsuario = ?;"
        dados = db.execute(sql, session["user_id"])
        return render_template("categoriaList.html", dados=dados)

@app.route("/despesas", methods=["GET", "POST"])
@login_required
def despesas():
    idUsuario = session["user_id"]
    dados = [{'id': '0', 'idTipoCategoria': 0, 'data': '', 'descricao': '', 'dataVencimento':'','valor': 0, 'consolidado': 0 }]
    sqlCategoria  = "Select id, descricao From Categoria where idUsuario = ? and idTipoCategoria = 1;"                
    categorias = db.execute(sqlCategoria, idUsuario)        
    print(categorias)                
    if request.method == "POST":
        id =  request.form.get("idDespesa")        
        if id != '0':
            try:
                sql = "Select d.*, l.consolidado From despesa d LEFT Join lancamentos l on d.idUsuario = l.idUsuario  and d.id = l.idDespesa where d.idUsuario = ? and d.id = ?;"
                dados = db.execute(sql, idUsuario , id)
                print(session["user_id"])
                print(id)
                print(dados )
                print(categorias)                
                print(dados)    
                           
                return render_template("despesas.html", dados=dados, categorias=categorias )
            except Exception as e:
                print(type(e))    # the exception type
                print(e.args)     # arguments stored in .args
                print(e)          # __str__ allows args to be printed directly,
                return {'Error' :'Erro ao renderizar formulário de despesas!', 'status':'403'}
        else:
            print(dados)
            return render_template("despesas.html", dados=dados,  categorias=categorias)
    return render_template("despesas.html", dados=dados, categorias=categorias)


@app.route("/despesaIncluir", methods=["GET", "POST"])
@login_required
def despesaIncluir():
    idUsuario = session["user_id"]
    idCategoria = request.form.get("idCategoria")
    data = request.form.get("data")
    descricao = request.form.get("descricao")
    dataVencimento = request.form.get("dataVencimento")
    valor = request.form.get("valor")
    valor = valor[3:16]
    valor = valor.replace('.', '')
    valor = float(valor.replace(',', '.'))
    print
    try:
        sql = "INSERT INTO Despesa(idUsuario,idCategoria,data, descricao, dataVencimento, valor) VALUES (?, " + idCategoria + " ,'" + data + "','" + descricao + "','" + dataVencimento + "', ?);"
        db.execute(sql, idUsuario, valor);
        jsonResponse = {"status":"200"}
        return jsonResponse
    except Exception as inst:
                print(type(inst))    # the exception type
                print(inst.args)     # arguments stored in .args
                print(inst)          # __str__ allows args to be printed directly,
                return {"Error": json.dumps(inst.args), "status": "400"}



@app.route("/despesaAlterar", methods=["GET", "POST"])
@login_required
def despesaAlterar():
    idDespesa = request.form.get("idDespesa")
    idUsuario = session["user_id"]
    idCategoria = request.form.get("id_Categoria")
    data = request.form.get("data")
    descricao = request.form.get("descricao")
    dataVencimento = request.form.get("dataVencimento")
    valor = request.form.get("valor")
    valor = valor[3:16]
    valor = valor.replace('.', '')
    valor = float(valor.replace(',', '.'))
   
    print(idDespesa)
    type(idDespesa)
    print(idUsuario)
    type(idUsuario)
    print(idCategoria)
    type(idCategoria)
    print(data)
    type(data)
    print(descricao)
    type(descricao)
    print(dataVencimento)
    type(dataVencimento)
    print(valor)

    try:
        sql = "UPDATE Despesa SET idCategoria =" + idCategoria +", data ='" +  data + "', descricao ='" + descricao +"', dataVencimento = '" + dataVencimento + "', valor = ? Where idUsuario = ? and id = ?;"
        db.execute(sql, valor, idUsuario, idDespesa );

        jsonResponse = {"idDespesa":idDespesa,"idUsuario":idUsuario,"idCategoria":idCategoria,"data":data,"descricao":descricao, "dataVencimento":dataVencimento, "valor":valor }
        jsonResponse = {"data": jsonResponse, "status":"200"  }
        return jsonResponse
    except Exception as e:
                print(type(e))    # the exception type
                print(e.args)     # arguments stored in .args
                print(e)          # __str__ allows args to be printed directly,
                return {"Error":"Erroo ao alterar despesas" , "status" : "403"}


@app.route("/despesaDelete", methods=["GET", "POST"])
@login_required
def despesaDelete():
    idDespesa =  request.form.get("idDespesa")
    try:
        idDespesa =  request.form.get("idDespesa")
        print(idDespesa)
        sql = "Delete  from Despesa where idUsuario = ? and id = ?;"
        db.execute(sql, session["user_id"], idDespesa)
        jsonResponse = {"status":"200", "idDespesa": idDespesa}
        return jsonResponse
    except Exception as inst:
                print(type(inst))    # the exception type
                print(inst.args)     # arguments stored in .args
                print(inst)          # __str__ allows args to be printed directly,
                return {"Error": 'Erro ao deletar despesa!', "status": "403"}

@app.route("/despesasList", methods=["GET", "POST"])
@login_required
def despesasList():

    sql =   "Select d.id, d.idUsuario, c.descricao as categoria, tc.descricao as tipo, strftime('%d/%m/%Y', d.data) as data, d.descricao, strftime('%d/%m/%Y', d.dataVencimento) as dataVencimento, d.valor  From Despesa d Inner Join Categoria c on d.idCategoria = c.id  Inner Join TipoCategoria tc on c.idTipoCategoria = tc.id  where d.idUsuario = ? and c.idTipoCategoria = 1;"
    dados = db.execute(sql, session["user_id"])        
    total = db.execute("Select sum(valor)as total from Despesa where idUsuario = ?;", session["user_id"])
    total = total[0]
    total = round(total['total'], 2 )        
    return render_template("despesasList.html", dados=dados, total=total)

@app.route("/receitas", methods=["GET", "POST"])
@login_required
def receitas():
    dados = [{'id': '0', 'idTipoCategoria': 0, 'data': '', 'descricao': '', 'dataVencimento':'','valor': 0, 'consolidado': 0 }]
    sqlCategoria  = "Select id, descricao From Categoria where idUsuario = ? and idTipoCategoria = 2;"                
    categorias = db.execute(sqlCategoria, session["user_id"])    
    if request.method == "POST":
        id =  request.form.get("idReceita")
        if id != '0':
            try:
                sql = "Select r.*, l.consolidado  From receita r  Left join lancamentos l on r.idUsuario = l.idUsuario  and r.id = l.idReceita where r.idUsuario = ? and r.id = ?"
                dados = db.execute(sql, session["user_id"], id)
                print(session["user_id"])
                print(id)
                print(dados )
                print(categorias)                
                print(dados)
                return render_template("receitas.html", dados=dados, categorias=categorias )
            except Exception as e:
                print(type(e))    # the exception type
                print(e.args)     # arguments stored in .args
                print(e)          # __str__ allows args to be printed directly,
                return {'Error' :'Erro ao renderizar formulário de receitas!', 'status':'403'}
        else:
            print(dados)
            return render_template("receitas.html", dados=dados,  categorias=categorias)
    return render_template("receitas.html", dados=dados, categorias=categorias)


@app.route("/receitaIncluir", methods=["GET", "POST"])
@login_required
def receitaIncluir():
    idUsuario = session["user_id"]
    idCategoria = request.form.get("idCategoria")
    data = request.form.get("data")
    descricao = request.form.get("descricao")
    valor = request.form.get("valor")
    valor = valor[3:16]
    valor = valor.replace('.', '')
    valor = float(valor.replace(',', '.'))
    print
    try:
        sql = "INSERT INTO Receita(idUsuario,idCategoria,data, descricao,  valor) VALUES (?, " + idCategoria + " ,'" + data + "','" + descricao + "', ?);"
        db.execute(sql, idUsuario, valor);
        jsonResponse = {"status":"200"}
        return jsonResponse
    except Exception as inst:
                print(type(inst))    # the exception type
                print(inst.args)     # arguments stored in .args
                print(inst)          # __str__ allows args to be printed directly,
                return {"Error": json.dumps(inst.args), "status": "400"}



@app.route("/receitaAlterar", methods=["GET", "POST"])
@login_required
def receitaAlterar():
    id = request.form.get("idReceita")
    idCategoria = request.form.get("idCategoria")
    idUsuario = session["user_id"]
    data = request.form.get("data")
    descricao = request.form.get("descricao")
    valor = request.form.get("valor")
    valor = valor[3:16]
    valor = valor.replace('.', '')
    valor = float(valor.replace(',', '.'))
    try:
        sql = "UPDATE Receita SET idCategoria =" + idCategoria +", data = '" +  data + "',descricao = '" + descricao + "', valor = ? Where idUsuario = ? and id = ?;"
        db.execute(sql, valor, idUsuario, id );

        jsonResponse = {"id":id,"categoria":idCategoria,"data":data,"descricao":descricao, "valor":valor }
        jsonResponse = {"data": jsonResponse, "status":"200"  }
        return jsonResponse
    except Exception as inst:
                print(type(inst))    # the exception type
                print(inst.args)     # arguments stored in .args
                print(inst)          # __str__ allows args to be printed directly,
                return {"Error":json.dumps(inst), "status": "400"}


@app.route("/receitaDelete", methods=["GET", "POST"])
@login_required
def receitaDelete():
    idReceita =  request.form.get("idReceita")
    try:
        idReceita =  request.form.get("idReceita")
        print(idReceita)
        sql = "Delete  from Receita where idUsuario = ? and id = ?;"
        db.execute(sql, session["user_id"], idReceita)
        jsonResponse = {"status":"200", "idReceita": idReceita}
        return jsonResponse
    except Exception as inst:
                print(type(inst))    # the exception type
                print(inst.args)     # arguments stored in .args
                print(inst)          # __str__ allows args to be printed directly,
                return {"Error": 'Erro ao deletar receita!', "status": "403"}

@app.route("/receitasList", methods=["GET", "POST"])
@login_required
def receitasList():

    sql =   "Select r.id, r.idUsuario, c.descricao as categoria, tc.descricao as tipo, strftime('%d/%m/%Y', r.data) as data, r.descricao, r.valor  From Receita r Inner Join Categoria c on r.idCategoria = c.id  Inner Join TipoCategoria tc on c.idTipoCategoria = tc.id  where r.idUsuario = ? and c.idTipoCategoria = 2;"
    dados = db.execute(sql, session["user_id"])

    total = db.execute("Select sum(valor)as total from Receita r Inner Join Categoria c on r.idCategoria = c.id where r.idUsuario = ? and idTipoCategoria = 2;", session["user_id"])
    total = total[0]
    total = round(total['total'], 2 )

    return render_template("receitasList.html", dados=dados, total=total)



@app.route("/lancamentos", methods=["GET", "POST"])
@login_required
def lancamentos():

    idUsuario = session["user_id"]
              
    sql = """Select  lancamentos.* 
               from (Select d.idUsuario, strftime('%d/%m/%Y', data) as fData,  idCategoria, valor*-1 as valor, 'Despesas' as tipo, d.id as idDespesa, 0 as idReceita, d.descricao, c.descricao as categoria
                       From Despesa d
                      Inner Join Categoria c on d.idCategoria = c.id
                      where d.idUsuario = ?
              union
                     Select r.idUsuario, strftime('%d/%m/%Y', data) as fData, idCategoria, valor, 'Receitas' as tipo, 0 as idDespesa, r.id as idReceita, r.descricao, cr.descricao as categoria
                       From Receita r
                      Inner Join Categoria cr on r.idCategoria = cr.id
                     where r.idUsuario = ?
                    ) as lancamentos;"""        
    dados = db.execute(sql, idUsuario, idUsuario)
    
    return render_template('lancamentos.html', dados=dados, total=getSaldo(idUsuario))


def getSaldo(idUsuario):
        
    saldoDespesa = "SELECT sum(valor) as saldo FROM Despesa Where idUsuario = ?"    
    saldoReceita =   "SELECT sum(valor) as saldo FROM Receita Where idUsuario = ?"
         
    saldoReceita = db.execute(saldoReceita, idUsuario)    
    saldoDespesa = db.execute(saldoDespesa, idUsuario)
    
    saldoDespesa = saldoDespesa[0]
    saldoReceita = saldoReceita[0]    
    
    saldo = round(saldoReceita['saldo'], 2 ) - round(saldoDespesa['saldo'], 2 )
    saldo = round(saldo, 2)
    
    return saldo