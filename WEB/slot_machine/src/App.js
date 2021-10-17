import React from "react"
import "./App.css"
import SlotMachine from "./SlotMachine"

function App() {
  var myArray = [
    "🙂",
    "🤖",
    "👽",
    "💀",
    "👻",
    "😛",
    "😝"
  ];
  return <>
    <h1 className="heading_Style">
      🎰 Welcome to <span style={{fontWeight:"bold", color:"blue"}}>Slot Machine Game 🎰</span> 
    </h1>
    <div className="slotmachine">
      <SlotMachine x={myArray[Math.floor(Math.random()*myArray.length)]} y={myArray[Math.floor(Math.random()*myArray.length)]} z={myArray[Math.floor(Math.random()*myArray.length)]}/>
      <hr />
      <SlotMachine x={myArray[Math.floor(Math.random()*myArray.length)]} y={myArray[Math.floor(Math.random()*myArray.length)]} z={myArray[Math.floor(Math.random()*myArray.length)]}/>
      <hr />
      <SlotMachine x={myArray[Math.floor(Math.random()*myArray.length)]} y={myArray[Math.floor(Math.random()*myArray.length)]} z={myArray[Math.floor(Math.random()*myArray.length)]}/>
      <hr />
      <SlotMachine x={myArray[Math.floor(Math.random()*myArray.length)]} y={myArray[Math.floor(Math.random()*myArray.length)]} z={myArray[Math.floor(Math.random()*myArray.length)]}/>
    </div>
  </>;
}

export default App;
