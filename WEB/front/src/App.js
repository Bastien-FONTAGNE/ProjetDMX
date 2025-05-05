import React from 'react';
import { BrowserRouter } from 'react-router-dom';
import Login from './login/Login.js';
import Home from './home/Home.js';

function App() {
  return (
    <BrowserRouter>
      <div>
        <Login />
        <Home />
      </div>
    </BrowserRouter>
  );
}

export default App;

