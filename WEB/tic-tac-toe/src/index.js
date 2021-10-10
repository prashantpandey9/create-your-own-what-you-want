import React, { useState } from 'react';
import ReactDOM from 'react-dom';
import './index.css';

const Square = (props) => {
  // const [value, setValue] = useState(null);

  return (
    <button className="square"
      // onClick={() => alert(`square ${props.value} clicked`)}
      onClick={props.onClickEvent}
      disabled={props.win}
    >
      {props.value === 'X' && <div className="X">{props.value}</div>}
      {props.value === 'O' && <div className="O">{props.value}</div>}
    </button>
  )
}

const ResetButton = (props) => {
  // const [value, setValue] = useState(null);

  return (
    <button className="reset"
      // onClick={() => alert(`square ${props.value} clicked`)}
      onClick={props.onClickResetEvent}
    >Reset
    </button>
  )
}

const Board = () => {
  const initialSquare = Array(9).fill(null);
  const [squares, setSquares] = useState(initialSquare); 
  const [xIsNext, setXIsNext] = useState(true);

  const handleClickEvent = (i) => {
    // alert(`square ${i} clicked`)
    //1. Make a copy of square state array
    const newSquares = [...squares];

    const winnerDeclared = Boolean(calculateWinner(newSquares));
    const squareFilled = Boolean(newSquares[i]);

    if(winnerDeclared || squareFilled){
      return;
    }
  
    //2. Mutate the copy, Setting the i-th element to 'X'
    newSquares[i] = xIsNext ? 'X' : 'O';
    //3. Call the setSquare funtion to mutated the copy

    setSquares(newSquares);
    setXIsNext(!xIsNext);
  }

  const renderSquare = (i) => {
    return(
      <Square 
        value={squares[i]} 
        onClickEvent={() => handleClickEvent(i)}
        win={winner}
      />
    )
  }

  const handleRestClickEvent = () =>{
    setSquares(initialSquare);
    setXIsNext(true);
  }

  const reset = () => {
    return(
      <ResetButton 
        onClickResetEvent={() => handleRestClickEvent()}
      />
    )
  }

  const winner = calculateWinner(squares);
  const check = checkSquares(squares);
  const status = winner ? `Winner: ${winner}` : (check ? `Game Over !` : `Next Player: ${xIsNext ? 'X' : 'O'}`);
  

  return (
    <div style={{
      backgroundColor: 'skyblue',
      margin: 10,
      padding: 20,
    }}>
      <div className="status">{status}</div>
      <div className="board-row">
        {renderSquare(0)}{renderSquare(1)}{renderSquare(2)}
      </div>
      <div className="board-row">
        {renderSquare(3)}{renderSquare(4)}{renderSquare(5)}
      </div>
      <div className="board-row">
        {renderSquare(6)}{renderSquare(7)}{renderSquare(8)}
      </div>
      {winner || check ? reset() : null}
    </div>
  )
}

const Game = () => {
  return (
    <div className="game">
      Tic-Tac-Toe
      <Board />
    </div>
  )
}

ReactDOM.render(
  // <React.StrictMode>
    <Game />, 
  // </React.StrictMode>,
  document.getElementById('root')
);

function calculateWinner(squares){
  const lines = [
    [0, 1, 2], [3, 4, 5], [6, 7, 8], //row
    [0, 3, 6], [1, 4, 7], [2, 5, 8], //cols
    [0, 4, 8], [2, 4, 6]  //diagonal   
  ]
  for (let line of lines){
    const [a, b, c] = line;
    if(squares[a] && squares[a] === squares[b] && squares[a] === squares[c]){
      return squares[a];
    }
  }
  return null;
}

function checkSquares(squares){
  for (var i=0; i<squares.length;i++){
    if(squares[i] == null){
      return false;
    }
  }
  return true;
}