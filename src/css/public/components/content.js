import React from 'react'

export default class Content extends React.Component {
    render() {
        return (
            <div className="content">
                <div className="content-wrapper">
                    <a href="https://accounts.google.com/o/oauth2/v2/auth?response_type=code&client_id=1003054041393-923o7gp7ip6844cvc9htjae30svmis65.apps.googleusercontent.com&redirect_uri=https%3A%2F%2Fconnect.presence.fortinet.com%2Fportal%2Foauth%2Fcallback%2Fgoogle&scope=https%3A%2F%2Fwww.googleapis.com%2Fauth%2Fplus.login+https%3A%2F%2Fwww.googleapis.com%2Fauth%2Fuserinfo.email&state=fa3E1ZHI8O068waJKcdWUV2o1Ul3PE&access_type=offline&approval_prompt=force">Google Login</a>
                </div>
                <footer className="footer">footer</footer>
            </div>
        )
    }
}