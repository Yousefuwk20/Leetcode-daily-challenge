class Solution {
	public:
		int numSteps(string s) {
			int k=0;
			while(s!="1"){
				if(s.back()=='0') s.pop_back();
				else{ 
					bool f=true;
					for(int i=s.size()-1;i>=0;i--){
						if(s[i]=='0'){
							s[i]='1';
							f=false;
							break;
						}
						else s[i]='0';
					}
					if(f) s.insert(0,"1");
				}
				k++;
			}
			return k;
		}
	};