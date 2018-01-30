import React from 'react'

export default class Header extends React.Component {
    render() {
        return (
            <div className="main-header">
                <a href="index.html" className="logo">
                    <span className="logo-lg">
                        <b>Grid</b>Demo
                    </span>
                </a>
            </div>
        )
    }
}