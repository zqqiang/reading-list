import React, { Component} from "react";
import styled from 'styled-components';

const Button = styled.button`
  border-radius: 3px;
  padding: 0.25em 1em;
  margin: 0 1em;
  background: transparent;
  color: palevioletred;
  border: 2px solid palevioletred;
`;

class App extends Component{
  render(){
    return(
      <div>
        <h1> Hello, World!</h1>
        <Button>Demo Button</Button>
      </div>
    );
  }
}

export default App;