import React from 'react';
import { Routes, Route } from 'react-router-dom';
import Login from './login/Login';
import Home from './home/Home';

function App() {
  return (
    <Routes>
      <Route path="/" element={<Login />} />
      <Route path="/home" element={<Home />} />
    </Routes>
  );
}

export default App;
 