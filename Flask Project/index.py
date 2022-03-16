from flask import Flask, render_template, request
from flask_wtf import FlaskForm
from wtforms import StringField, SubmitField
from wtforms.validators import DataRequired
app = Flask(__name__)
app.config['SECRET_KEY'] = "secretkey"
# form class


class NameForm(FlaskForm):
    name = StringField("What's your Name", validators=[DataRequired()])
    submit = SubmitField("Submit")


@app.route('/')
def index():
    first_name = "Huy"
    favorite_pizza = ["pepperoni", "sausage", "cheese", 10]
    return render_template('index.html', first_name=first_name, favorite_pizza=favorite_pizza)


@app.route('/name', methods=['GET', 'POST'])
def userForm():
    name = None
    form = NameForm()
    if form.validate_on_submit():
        name = form.name.data
        form.name.data = ''
    return render_template('name.html', name=name, form=form)


@app.route('/user/<name>')
def user(name):
    return render_template('user.html', name=name)


@app.errorhandler(404)
def page_not_found(e):
    return render_template('404.html'), 404


@app.errorhandler(500)
def page_not_found(e):
    return render_template('500.html'), 500
