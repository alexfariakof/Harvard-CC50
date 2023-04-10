from flask import Flask
from datetime import datetime
from pytz import datetime

app = Flask(__name__)

@app.route("/")
def index():
    now = datetime.now(timezone('America/Brasilia'))
    return "The current date and time in Cambridge is {}".format(now)
