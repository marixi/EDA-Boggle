//====================================================================================================
bool findWordAux(const vector<vector<char>> &board, vector<vector<bool>> &visited, int i, int j,
  string& str, const string &word, bool &found)
{
  // Mark current board cell as visited and 
  // append current character to 'str'
  visited[i][j] = true;
  str = str + board[i][j];

  // If 'str' is equal to 'word', then "announce" it has been found
  if (str == word)
  {
    found = true;
  }
  else
  {
    // Visit 8 adjacent cells of board[i][j] 
    for (int row = i - 1; row <= i + 1 && row < NUM_ROWS; row++)
      for (int col = j - 1; col <= j + 1 && col < NUM_COLS; col++)
        if (row >= 0 && col >= 0 && !visited[row][col] && str.length() < word.length() && !found && word.substr(0, str.length()) == str)
          findWordAux(board, visited, row, col, str, word, found);

    // Erase current character from string, 
    // remove character position from 'path' and
    // mark visited[i][j] as false
    if (!found)
    {
      str.erase(str.length() - 1);
      visited[i][j] = false;
    }
  }
  return found;
}

//====================================================================================================
// Finds word on board 
bool findWord(const vector<vector<char>> &board, string word)
{
  // Mark all characters as not visited 
  vector<vector<bool>> visited(NUM_ROWS, vector<bool>(NUM_COLS, false));

  // Initialize test word 
  string str = "";

  // Consider every character and look for 'word', starting with this character
  int numIter = 0;
  bool found = false;
  for (int i = 0; i < NUM_ROWS; i++)
    for (int j = 0; j < NUM_COLS; j++)
      if (board[i][j] == word[0])
        findWordAux(board, visited, i, j, str, word, found);
  return found;
}
//====================================================================================================