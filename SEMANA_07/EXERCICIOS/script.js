var contador1 = 0;
var contador2 = 0;
var finalizou = 0;
function jogador1(){
    if(contador1 < 10 && contador2 < 10){
    contador1++;
    $("#1-" + String(11 - contador1)).prop('src', 'https://png.pngtree.com/thumb_back/fw800/background/20210207/pngtree-blue-pure-color-simple-background-image_557085.jpg');    
    }
    else{
        if(finalizou == 0){
            alert("O jogador 1 venceu!");
        }
        finalizou = 1;
        encerrar();
    }
}
function jogador2(){
    if(contador2 < 10 && contador1 < 10){
        contador2++;
        $("#2-" + String(11 - contador2)).prop('src', 'https://png.pngtree.com/thumb_back/fw800/background/20210207/pngtree-red-background-simple-solid-color-image_556955.jpg');    
    }
    else{
        if(finalizou == 0){
            alert("O jogador 2 venceu!");
        }
        finalizou = 1;
        encerrar();
    }
}
function encerrar(){
    $("#botao2").addClass("disabled");
    $("#botao1").addClass("disabled");
}
function reiniciar(){
    contador1 = 0;
    contador2 = 0;
    finalizou = 0;
    $("#botao2").removeClass("disabled");
    $("#botao1").removeClass("disabled");
    for(i=1; i<=10; i++){
        $("#1-" + String(i)).prop('src', 'https://i0.wp.com/www.multarte.com.br/wp-content/uploads/2018/12/fundo-branco-liso2-1024x1024.jpg?resize=696%2C696&ssl=1');
        $("#2-" + String(i)).prop('src', 'https://i0.wp.com/www.multarte.com.br/wp-content/uploads/2018/12/fundo-branco-liso2-1024x1024.jpg?resize=696%2C696&ssl=1');
    }
}