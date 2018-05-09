import React, { Component} from "react";
import styled from 'styled-components';

const Header = styled.header`
  position: relative;
  max-height: 100px;
  z-index: 1030;
`;

const LogoLink = styled.a`
  background-color: #367fa9;
  color: #fff;
  order-bottom: 0 solid transparent;
  transition: width .3s ease-in-out;
  display: block;
  float: left;
  height: 50px;
  font-size: 20px;
  line-height: 50px;
  text-align: center;
  width: 230px;
  font-family: "Helvetica Neue",Helvetica,Arial,sans-serif;
  padding: 0 15px;
  font-weight: 300;
  overflow: hidden;
`;

class App extends Component{
  render(){
    return(
      <Header>
        <LogoLink>
          <span className="logo-lg"><b>Styled</b>Component</span>
        </LogoLink>
      </Header>
    );
  }
}

export default App;