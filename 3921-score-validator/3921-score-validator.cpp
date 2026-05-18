class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score =0;
        int counter = 0;
        for(int i =0;i<events.size();i++){
            if(events[i] == "W"){
                counter+= 1;
                if(counter ==10){
                    break;
                }
            }
            else if(events[i] == "WD" || events[i] == "NB"){
                score  = score+ 1;
            }
            else{
                score = score + stoi(events[i]);
            }
        }
        return {score , counter};
    }
};