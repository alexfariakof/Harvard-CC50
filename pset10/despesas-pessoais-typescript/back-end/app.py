from flask import *

app = Flask("__app__")


@app.route("/")
def index():
    return render_template("index.html", flask_token="React com PYTHON" )

app.run