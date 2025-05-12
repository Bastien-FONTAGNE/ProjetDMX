const express = require('express');
const cors = require('cors');
const mysql = require('mysql2');
const app = express();
const PORT = 3001;

// Middleware
app.use(cors());
app.use(express.json());

// Connexion à la base de données
const db = mysql.createConnection({
=======
    host: "127.0.0.1",
    user: "root",
    password: "********",
    database: "Projet_BTS"
});

// Test de connexion
db.connect(err => {
  if (err) {
    console.error('Erreur de connexion à la base de données :', err);
  } else {
    console.log('Connecté à la base de données MySQL.');
  }
});

// Route de test
app.get('/', (req, res) => {
  res.send('Backend fonctionnel !');
});

// Route de login réelle
app.post('/login', (req, res) => {
  const { username, password } = req.body;

  if (!username || !password) {
    return res.status(400).json({ success: false, message: 'Champs manquants' });
  }

  const query = 'SELECT * FROM User WHERE Username = ? AND Passhash = ?';
  db.query(query, [username, password], (err, results) => {
    if (err) {
      console.error('Erreur lors de la requête :', err);
      return res.status(500).json({ success: false, message: 'Erreur serveur' });
    }

    if (results.length > 0) {
      return res.json({ success: true, token: 'fake-jwt-token' });
    } else {
      return res.status(401).json({ success: false, message: 'Identifiants invalides' });
    }
  });
});

// Lancer le serveur
app.listen(PORT, () => {
  console.log(`Serveur backend démarré sur http://localhost:${PORT}`);
});
