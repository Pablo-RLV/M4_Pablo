const OFFSET_X = window.innerWidth/2;
const OFFSET_Y = window.innerHeight/2;
const SPEED = 0.6;
var controle = 2;
var dict = {angle_1: 2.0, scalar_1: 3.5, angle_2: 2.0, scalar_2: 3.5};
function setup() { 
    createCanvas(window.innerWidth, window.innerHeight);  
    noStroke();
    background (0);
} 
function draw() {
    cor1 = controle/2;
    cor2 = controle/2;
    cor3 = controle/2;
    x_1 = OFFSET_X + cos(dict.angle_1/2) * dict.scalar_1;
    y_1 = OFFSET_Y + sin(dict.angle_1/2) * dict.scalar_1;
    x_2 = OFFSET_X + sin(dict.angle_2/2) * dict.scalar_2;   
    y_2 = OFFSET_Y + cos(dict.angle_2/2) * dict.scalar_2;
    for (var key in dict) {
        dict[key] += SPEED;
    }
    fill(cor1,cor2,cor3);
    ellipse(x_1, y_1, 5);
    fill(cor1,cor2,cor3);
    ellipse(x_2, y_2, 5);
    noStroke();
    controle++;
    if(controle > 483){
        controle = 2;
        dict = {angle_1: 2.0, scalar_1: 3.5, angle_2: 2.0, scalar_2: 3.5};
    }
}