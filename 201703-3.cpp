//
// Created by Saijun Hu on 2019-02-26.
// TODO 我测试的很长时间了，可交上去就是0分，，，郁闷，先跳过了

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;
vector<vector<string>> article;

string parse_line(string line){
    size_t left,right;
    if((left = line.find('_'))!=string::npos){
        right=line.find('_',left+1);
        string sub_string = "<em>"+parse_line(line.substr(left+1,right-left-1))+"</em>";
        line.replace(left,right-left+1,sub_string);
        return parse_line(line);
    }else if((left=line.find('['))!=string::npos){
        right=line.find(']',left+1);
        string before_link=line.substr(0,left);
        string link_text=line.substr(left,right-left+1);
        size_t l=line.find('['),r=line.find(']',l+1);
        string link=line.substr(l,r-l+1);
        string after_link=line.substr(r,line.length()-r+1);
        return parse_line(parse_line(before_link)+"<a href=\""+parse_line(link)+">"+parse_line(link_text)+"</a>"+parse_line(after_link));
    }else{
        return line;
    }
}
void parse_block(vector<string> block){
    vector<string> res;
    for (auto line: block) {
        stringstream ss(line);string word;
        ss>>word;

        if(word.front()=='#'){//head
            string title;ss>>title;
            int level = word.length();
            res.push_back("<h"+to_string(level)+">"+parse_line(title)+"</h"+to_string(level)+">");
        }
        else if(word=="*"){//list
            if(line==block.front()) res.push_back("<ul>");
            string item;ss>>item;
            res.push_back("<li>"+parse_line(item)+"</li>");
            if(line==block.back()) res.push_back("</ul>");
        }
        else{//p
            if(block.size()==1) {res.push_back("<p>"+parse_line(line)+"</p>"); }
            else if (line==block.back()) { res.push_back(parse_line(line)+"</p>");}
            else if (line==block.front()) {
                res.push_back("<p>"+parse_line(line));
            }else{
                res.push_back(parse_line(line));
            }
        }

    }
    article.push_back(res);
}
int main(){
    string line;vector<string> block;
    while(getline(cin,line)){
        if(!line.empty()) block.push_back(line);
        else{ parse_block(block); block.clear(); }
    }
    for (auto block : article) {
        for ( auto line: block) cout<<line<<endl;
        cout<<endl;
    }
    return 0;
}

