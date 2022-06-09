const express = require('express')
const app = express()
const mysql = require('mysql')
const cors = require('cors')

app.use(express.json())

app.use(cors())
const db = mysql.createConnection({
    user: 'root',
    host: 'localhost',
    password: 'password',
    database: 'tenantsystem'
});

app.post('/create', (req, res) => {
    console.log(req.body.name)
    console.log(req.body.age)
    console.log(req.body.address)
    console.log(req.body.rent)
    console.log(req.body.leaseLength)
    console.log(req.body.startDate)
    const name = req.body.name
    const age = req.body.age
    const address = req.body.address
    const rent = req.body.rent
    const leaseLength = req.body.leaseLength
    const startDate = req.body.startDate

    db.query(
        "INSERT INTO tenants (name, age, address, rent, lease_length, start_date) VALUES (?,?,?,?,?,?)",
        [name, age, address, rent, leaseLength, startDate],
        (err, result) => {
            if (err) {
                console.log(err);
            } else {
                res.send("Values Inserted");
            }
        }
    );

});

app.get('/tenants', (req, res) => {
    db.query(
        'SELECT * from tenants', (err, result) => {
            if (err) {
                console.log(err)
            }
            else {
                res.send(result)
            }
        }
    )
});

app.put('/updateRent', (req, res) => {
    const id = req.body.id;
    const rent = req.body.rent;
    db.query(
        "UPDATE tenants SET rent = ? WHERE id = ?", [rent, id], (err, result) => {
            if (err) {
                console.log(err)
            } else {
                res.send(result)
            }
        }
    )
});

app.put('/updateLease', (req, res) => {
    const id = req.body.id;
    const leaseLength = req.body.leaseLength;
    db.query(
        "UPDATE tenants SET lease_length = ? WHERE id = ?", [leaseLength, id], (err, result) => {
            if (err) {
                console.log(err)
            } else {
                res.send(result)
            }
        }
    )
});

app.put('/updateName', (req, res) => {
    const id = req.body.id;
    const name = req.body.name;
    db.query(
        "UPDATE tenants SET name = ? WHERE id = ?", [name, id], (err, result) => {
            if (err) {
                console.log(err)
            } else {
                res.send(result)
            }
        }
    )
});

app.put('/updateAddress', (req, res) => {
    const id = req.body.id;
    const address = req.body.address;
    db.query(
        "UPDATE tenants SET address = ? WHERE id = ?", [address, id], (err, result) => {
            if (err) {
                console.log(err)
            } else {
                res.send(result)
            }
        }
    )
});

app.delete("/delete/:id", (req, res) => {
    const id = req.params.id
    db.query("DELETE FROM tenants WHERE id = ?", id, (err, result) => {
        if (err) {
            console.log(err);
        } else {
            res.send(result);
        }
    });
});

app.listen(3001, () => {
    console.log("Server is running...")
})