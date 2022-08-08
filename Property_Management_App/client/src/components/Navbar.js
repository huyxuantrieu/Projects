import { Link } from 'react-router-dom'


function Navbar() {
    return (
        <div className="navbar">
            <h1 className="navbar-title"> Property Management App</h1>
            <Link to="/"> Home Button </Link>
            <br></br>

            <Link to="/ContactForm"> Contact Form</Link>
            <br></br>

            <Link to="/NewUserForm"> New Tenant Form</Link>
            <br></br>

            <Link to="/Todo"> Todo List</Link>
            <br></br>
        </div >

    )
}

export default Navbar;
