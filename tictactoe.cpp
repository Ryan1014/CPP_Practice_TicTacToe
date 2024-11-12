#include <iostream> 

  char board[3][3] = {{'_','_','_'},{'_','_','_'},{'_','_','_'}};

  int Row = 0;
  int Col = 0;
  char Player = 'X';
  
void showGrid(int,int,char);
void switchPlayer();
bool checkWinner(char);

int main(){
  int round = 1;
  bool winner = false;

  std::cout << "Let's play Tic Tac Toe\n";

  while(round <= 9 && winner == false){
    std::cout << Player << " please choose a row: ";
    std::cin >> Row;
    std::cout << Player << " please choose a column: ";
    std::cin >> Col;
    if(board[Row-1][Col-1] == '_'){
      showGrid(Row,Col,Player);
      //check for winning game
      winner = checkWinner(Player);
      //switch to next palyer
      if(winner == false) switchPlayer(); // if ther is no winner yet switch to next player
      round++;
    }else{
      std::cout << "That space is taken or out of bounds try agian!\n";
    }   
  }  
  if(winner){
    std::cout << Player << " wins!";
  }else{
    std::cout << " Cat's Game";
    }
}

void showGrid(int row, int col, char letter){
  board[row-1][col-1] = letter;
  for(int x = 0; x < 3; x++){
    for(int y = 0; y < 3; y++){
      std::cout << board[x][y];
    }
    std::cout << "\n";
  }
}

void switchPlayer(){
      if(Player == 'X'){
        Player = 'O';
      }else {
        Player = 'X';
      }
}

bool checkWinner(char Player){
  //Check if the last move was a winning move. If so, that palyer wins.
  if(board[0][0] == Player && board[0][1] == Player && board[0][2] == Player){ 
    return true;
  }else if(board[1][0] == Player && board[1][1] == Player && board[1][2] == Player){ 
    return true;
  }else if(board[2][0] == Player && board[2][1] == Player && board[2][2] == Player){ 
    return true;
  }else if(board[0][0] == Player && board[1][0] == Player && board[2][0] == Player){ 
    return true;
  }else if(board[0][1] == Player && board[1][1] == Player && board[2][1] == Player){ 
    return true;
  }else if(board[0][2] == Player && board[1][2] == Player && board[2][2] == Player){ 
    return true;
  }else if(board[0][0] == Player && board[1][1] == Player && board[2][2] == Player){ 
    return true;
  }else if(board[0][2] == Player && board[1][1] == Player && board[2][0] == Player){ 
    return true;
  }else return false;
}
