const express = require("express");
const path = require("path");
const mysql = require("mysql2");
const cors = require("cors");
const bcrypt = require("bcrypt");

const app = express();
const PORT = 3000;

// Middleware
app.use(express.json());
app.use(cors({ credentials: true, origin: "*" }));

// Servir les fichiers statiques depuis /var/www/html/Projet_BTS
app.use(express.static(path.join(__dirname, "../")));

// Rediriger vers accueil.html quand on visite la racine
app.get("/", (req, res) => {
    res.sendFile(path.join(__dirname, "../index.html"));
});

// Connexion à la base de données
const db = mysql.createConnection({
    host: "127.0.0.1",
    user: "root",
    password: "********",
    database: "Projet_BTS"
});

db.connect(err => {
    if (err) console.error("Erreur de connexion à MySQL :", err);
    else console.log("Connecté à MySQL");
});

// Connexion utilisateur
app.post("/login", (req, res) => {
    const { username, password } = req.body;

    db.query("SELECT * FROM User WHERE Username = ?", [username], async (err, results) => {
        if (err) return res.status(500).send("Erreur serveur");
        if (results.length === 0) return res.status(401).send("Identifiants incorrects");

        const user = results[0];

        // Comparaison du mot de passe avec bcrypt
        const match = await bcrypt.compare(password, user.passhash);
        if (match) {
            return res.sendStatus(200);
        } else {
            return res.status(401).send("Identifiants incorrects");
        }
    });
});

// Ajout d'un utilisateur (nécessite un compte admin)
app.post("/addUser", async (req, res) => {
    const { adminUsername, adminPassword, newUsername, newPassword } = req.body;

    // Vérification que l'admin existe
    db.query("SELECT * FROM User WHERE Username = ?", [adminUsername], async (err, results) => {
        if (err) return res.status(500).send("Erreur serveur");
        if (results.length === 0) return res.status(403).send("Accès refusé");

        const admin = results[0];
        const isAdmin = await bcrypt.compare(adminPassword, admin.passhash);
        if (!isAdmin) return res.status(403).send("Accès refusé");

        // Hashage du nouveau mot de passe
        const hashedPassword = await bcrypt.hash(newPassword, 10);

        // Insertion du nouvel utilisateur
        db.query("INSERT INTO User (Username, passhash) VALUES (?, ?)", [newUsername, hashedPassword], (err) => {
            if (err) return res.status(500).send("Erreur serveur");
            res.sendStatus(201);
        });
    });
});

// Récupération des trames DMX
app.get("/trames", (req, res) => {
    db.query("SELECT id FROM Scene", (err, results) => {
        if (err) return res.status(500).send("Erreur serveur");
        res.json(results);
    });
});

// Lancer le serveur
app.listen(PORT, "0.0.0.0", () => {
    console.log(`Serveur accessible sur http://192.168.64.50:${PORT}`);
});
