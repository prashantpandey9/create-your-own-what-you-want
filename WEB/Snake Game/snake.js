
//drawing the canvas on the screen
const canvas=document.getElementById('game');
const ctx=canvas.getContext('2d');

//track the length of the snake
class SnakePart {
    constructor(x, y) {
      this.x = x;
      this.y = y;
    }
  }

//Speed with which the snake moves
let speed=5;

//defining the variables we need for printing our snake on the screen.
let tileCount=20; //Assuming total tiles on our canvas as 30
let tileSize=canvas.width/tileCount -2;//we dont want snake to go to absolute end 
let xhead=6;  // Initial position of snake is at centre ,so head is 15.
let yhead=6;  // Initial position of snake is at centre , so tail is 15.

const snakeParts=[];
let tailLength=0;//length of the tail of snake
let xfood=5; // x-co-ordinate of apple
let yfood=5;// y-co-ordinate of apple

let score=0;//score
//To move the snake
let xVelocity=0;
let yVelocity=0;


//The main function of game
function Game()
{
    SnakePosition();
    let result=isGameOver();
    if (result)
    {
        return ;
    }
    clearScreen();
    checkFoodCollision();
    drawFood();
    drawSnake();
    drawScore();
    if(score>2)
    {
        speed+=0.05;//increasing the speed as score
    }
    setTimeout(Game,2500/speed);
}

//Game over
function isGameOver()
{
    let gameOver=false;


    //walls
    if(xhead<0)
    {
        gameOver=true;
    }
    else if (xhead === tileCount)
    {
        gameOver = true;
    }
     else if (yhead < 0) 
    {
        gameOver = true;
    }
     else if (yhead === tileCount)
    {
        gameOver = true;
    }
    for (let i = 0; i < snakeParts.length; i++) 
    {
        let part = snakeParts[i];
        if (part.x === xhead && part.y === yhead) 
        {
          gameOver = true;
          break;
        }
    }
    if (gameOver) {
        ctx.fillStyle = "black";
        ctx.font = "50px Verdana";
        ctx.fillText("Game Over!", canvas.width / 6.5, canvas.height / 2);
      }
  
      ctx.fillText("Game Over!", canvas.width / 6.5, canvas.height / 2);
      return gameOver;
}
//draw the score
function drawScore()
{
    ctx.fillStyle='white';
    ctx.font="10px Verdana";
    ctx.fillText("Score "+score,canvas.width-50,10);
}   

//clear the screen after every game over
function clearScreen()
{
    ctx.fillStyle='white';
    ctx.fillRect(0,0,canvas.width,canvas.height);
}

//Drawing snake on the canvas/board
function drawSnake() {
    ctx.fillStyle = "black";
    for (let i = 0; i < snakeParts.length; i++) {
      let part = snakeParts[i];
      ctx.fillRect(part.x * tileCount, part.y * tileCount, tileSize, tileSize);
    }
  // increment the snake when it eats apples.
    snakeParts.push(new SnakePart(xhead, yhead)); //put an item at the end of the list next to the head
    while (snakeParts.length > tailLength) {
      snakeParts.shift(); // remove the furthet item from the snake parts if have more than our tail size.
    }
  
    ctx.fillStyle = "red";
    ctx.fillRect(xhead * tileCount, yhead * tileCount, tileSize, tileSize);
  }
// to draw the apple on the screen
function drawFood()
{
    ctx.fillStyle='green';
    ctx.fillRect(xfood*tileCount,yfood*tileCount,tileSize,tileSize);
}

// change snake position as it moves
function SnakePosition()
{
    xhead=xhead+xVelocity;
    yhead=yhead+yVelocity;
}

//if snake eats apple , change the position of apple
function checkFoodCollision()
{
    if(xfood===xhead && yfood===yhead)
    {
        xfood=Math.floor(Math.random()*tileCount);
        yfood=Math.floor(Math.random()*tileCount);
        tailLength++;
        score++;
    }
}

//movement of the snake
document.body.addEventListener('keydown',keyDown);
function keyDown(event)
{
    //up
    if(event.keyCode==38)
    {
        if(yVelocity==1)
        return;
        yVelocity=-1;
        xVelocity=0;
    }
    //down
    if(event.keyCode==40)
    {
        if(yVelocity==-1)
        return;
        yVelocity=1;
        xVelocity=0;
    }
    //left
    if(event.keyCode==37)
    {
        if(xVelocity==1)
        return;
        yVelocity=0;
        xVelocity=-1;
    }
    //right
    if(event.keyCode==39)
    {
        if(xVelocity==-1)
        return;
        yVelocity=0;
        xVelocity=1;
    }
}


Game();