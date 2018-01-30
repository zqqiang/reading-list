import React from 'react'

import Header from './header'
import Navbar from './navbar'
import Sidebar from './sidebar'
import Content from './content'

export default class App extends React.Component {
    render() {
        return (
            <div className="wrapper">
                <Header />
                <Navbar />
                <Sidebar />
                <Content />
            </div>
        )
    }
}