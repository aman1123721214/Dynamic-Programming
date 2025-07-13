class Solution {
  static solve(ind, str, st){
    if(ind == str.length) return true;

    let temp = "";
    for(let i = ind; i<str.length; i++){
        temp+=str[i];
        if(st.has(temp)){
            if(Solution.solve(i+1, str, st)) return true;
        }
    }
    return false;
  }
  wordBreak(n, s,dictionary){
    //code here
    const st = new Set(dictionary);
    return Solution.solve(0, s, st)?1:0;
  }
}