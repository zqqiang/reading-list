import React from 'react'

export default class Navbar extends React.Component {
    render() {
        return (
            <div className="main-navbar">
                <nav className="navbar navbar-static-top">
                    <div className="navbar-custom-menu">
                        <ul className="nav navbar-nav">
                            <li className="dropdown messages-menu">
                                <a href="#" className="dropdown-toggle">
                                    <i className="fa fa-envelope-o"></i>
                                    <span className="label label-success">4</span>
                                </a>
                            </li>
                        </ul>
                    </div>
                </nav>
            </div>
        )
    }
}