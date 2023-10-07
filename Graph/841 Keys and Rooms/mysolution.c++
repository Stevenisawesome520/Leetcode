class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int len = rooms.size();
        vector<bool> unlocked(len, false);
        unlocked[0] = true;
        queue<int> que;
        for(int i = 0; i < rooms[0].size(); i++)
        {
            que.push(rooms[0][i]);
            unlocked[rooms[0][i]] = true;
        }        
        while(que.size())
        {
            int size = que.size();
            for(int i = 0; i < size; i++)
            {
                int room = que.front();
                que.pop();

                for(int j = 0; j < rooms[room].size(); j++)
                {
                    if(!unlocked[rooms[room][j]])
                    {
                        que.push(rooms[room][j]);
                        unlocked[rooms[room][j]] = true;
                    }
                }
            }
        }

        for(int i = 0; i < len; i++)
            if(!unlocked[i])
                return false;
        
        return true;
    }
};
