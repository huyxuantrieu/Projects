const express = require("express");
const app = express();
const mongoose = require("mongoose");
const UserModel = require("./models/Users");

app.use(express.json());
mongoose.connect('mongodb+srv://huyxuantrieu:87654321@cluster0.lkj4t.mongodb.net/user_database?retryWrites=true&w=majority');

app.get("/getUsers", (req, res) => {
    UserModel.find({}, (err, result) => {
        if (err) {
            res.json(err);
        } else {
            res.json(result);
        }
    });
});

app.listen(3001, () => {
    console.log("SERVER RUNNING...");
});