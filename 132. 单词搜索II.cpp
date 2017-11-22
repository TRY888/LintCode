class Solution {
public:
    /*
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    int row_max;
	int col_max;
	vector<vector<bool> > flags;
     
    int search(vector<vector<char> > &board, string word, int pos_x, int pos_y)
    {
        if(word.size() == 0)
			return true;
		flags[pos_x][pos_y] = true;
		if(pos_x-1>=0 && board[pos_x-1][pos_y] == word[0] && flags[pos_x-1][pos_y] == false)
		{
		    if(search(board, word.substr(1), pos_x-1, pos_y))
		        return true;
		    flags[pos_x-1][pos_y] = false;
		}
		if(pos_y+1<col_max && board[pos_x][pos_y+1] == word[0] && flags[pos_x][pos_y+1] == false)
		{
		    if(search(board, word.substr(1), pos_x, pos_y+1))
		        return true;
		    flags[pos_x][pos_y+1] = false;
		}
		if(pos_x+1<row_max && board[pos_x+1][pos_y] == word[0] && flags[pos_x+1][pos_y] == false)
		{
		    if(search(board, word.substr(1), pos_x+1, pos_y))
		        return true;
		    flags[pos_x+1][pos_y] = false;
		}
		if(pos_y-1>=0 && board[pos_x][pos_y-1] == word[0] && flags[pos_x][pos_y-1] == false)
		{
		    if(search(board, word.substr(1), pos_x, pos_y-1))
		        return true;
		    flags[pos_x][pos_y-1] = false;
		}
		return false;
    }
    
    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words)
    {
        // write your code here
        vector<string> res;
        row_max = board.size();
		if(row_max == 0)
			return res;
		else
			col_max = board[0].size();
		flags.resize(row_max);
		for(int i=0; i<row_max; i++)
		{
		    flags[i].resize(col_max, false);
		}
		
		for(int i=0; i<words.size(); i++)
		{
			if(words[i].size()==0)
				continue;
			for(int j=0; j<row_max; j++)
			{
				for(int k=0; k<col_max; k++)
				{
					if(board[j][k] == words[i][0] && search(board, words[i].substr(1), j, k))
					{
						res.push_back(words[i]);
                        goto next;
					}
					flags[j][k] = false;
				}
			} 
next:		for(int m=0; m<row_max; m++)
			{
			    for(int n=0; n<col_max; n++)
			        flags[m][n] = false;
			}
		}
    }
};

