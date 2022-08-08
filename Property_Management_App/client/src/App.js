import './App.css';
import Navbar from './components/Navbar';
import { BrowserRouter, Routes, Route } from 'react-router-dom'
import Home from './components/Home';
import ContactForm from './components/ContactForm.js';
import AddTenant from './components/AddTenant.js';
import Background from './components/Background';
import Todo from './components/Todo.js';


function App() {


  return (
    <div className="App">
      <div className="body">
        <Background />
        <BrowserRouter>
          <Navbar />
          <Routes>
            <Route path="/" element={<Home />} />
            <Route path="/ContactForm" element={<ContactForm />} />
            <Route path="/NewUserForm" element={<AddTenant />} />
            <Route path="/Todo" element={<Todo />} />
          </Routes>
        </BrowserRouter>
      </div>
    </div>
  );
}

export default App;
