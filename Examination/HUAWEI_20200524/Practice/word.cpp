/************************************************************************************
２.已知：一个单词列表std::vector<std::string> dict={"big","bit","dig","bag","dog"}和给定的
两个单词src和ｄst
要求：以src为起点从单词列表中逐次寻找一个单词进行变换，每次变换只改变一个字母，直到dst，计算从src变换
到dst，计算从src变换到dst的最小次数，若没有能变换成功的路径，则返回０。举例：std::string src="gog"，
std::string dst="bag"，则gog->dog->dig->big->bag，return 4。
************************************************************************************/


class Solution {
public:
    bool calnotsame(string &beginWord, string &endWord){
        int cnt=0;
        for(int i=0;i<beginWord.length();i++){
            if(beginWord[i]!=endWord[i]){
                cnt++;
            }
        }
        return cnt==1;//只有一个字符相同才能转换，才有效
    }
 
    void makegraph(string &beginWord, vector<string>& wordList,map<string,vector<string>>&graph){
        wordList.push_back(beginWord);//要查找的节点必须也存入wordlist，看哪些string能接到
        for(int i=0;i<wordList.size();i++){
            graph[wordList[i]]=vector<string>();//初始化临接表
        }
        for(int i=0;i<wordList.size();i++){
            for(int j=i+1;j<wordList.size();j++){
                if(calnotsame(wordList[i],wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);//互相都能访问，双向存储
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
    }    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,vector<string>>graph;
        makegraph(beginWord, wordList,graph);
        queue<pair<string,int>>Q;//你的查找队列
        set<string>visit;//记录访问结果
        Q.push(make_pair(beginWord,1));//从begin开始变换，并与步数一起存入
        visit.insert(beginWord);//加入已visit里
        while(!Q.empty()){//当队列里有节点
            string node=Q.front().first;//取出当前的字符串
            int step=Q.front().second;//取出当前运行的步数
            Q.pop();//得到后这个节点pop出去
            if(node==endWord)
                return step;//宽搜找到了，就是最小的步数，因为会把每一个点的临接都遍历完才到下一个点
            const vector<string>&neighbors=graph[node];//存一下临接的表们
            for(int i=0;i<neighbors.size();i++){
            if(visit.find(neighbors[i])==visit.end()){//如果临接这个string没被搜索过
                Q.push(make_pair(neighbors[i],step+1));//加进队列
                visit.insert(neighbors[i]);//加进visit
            }
        }
        }
        return 0;//无法转换
    }
};
