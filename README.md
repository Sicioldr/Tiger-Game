# Tiger-Game  
STUFF DONE:

  included color to token with apropriate functions
  
  included old location to Token
  
  changed name of alive status of hunter and added accessor
  
  made all of board public
  
  added plotBoard to board class
  
  created plotTokens in board class
  
  bool tigerTurn in main, can be moved to board if desired
  
  reworked click to only funcion on team whose turn it is
  
  made game click to select and click to drop



STUFF TO DO:

  add valid move function into tigers turn in main...
    info: old location still held in location, new location is vertexToNode(x,y)
    
  be able to kill people...
    add approrpiate function in tigers turn; 
    need to: determine if jumped node was occupied, and if so: kill() man, set Node to unoccupied
    
  add valid move function to hunters turn...
    info: same available info for parameters
    
   test game over
   
   if time, game over screen
    
    
PROBLEMS:

    sometimes leaves a bit of green on screen (just move reasonably slow to fix)
		
    X button doesnt close program
