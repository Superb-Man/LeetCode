
int candy(int* ratings, int ratingsSize) {
    int dec = 0;
    int cur = 1;
    int tot = 1;
    int maxCur = 1;

    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] < ratings[i-1]) {
            dec++;
        } 
        else {
            if (dec) {
                tot += (dec*(dec+1))/2;
                if (maxCur <= dec) {
                    tot += dec-maxCur+1;
                }
                dec = 0;
                cur = 1;
            }
            cur = (ratings[i] == ratings[i-1]) ? 1 : cur + 1;
            maxCur = cur;
            tot += cur;
        }
    }

    if (dec) {
        tot += (dec*(dec+1))/2;
        if (maxCur <= dec)  tot += dec-maxCur+1;
    }

    return tot;
}
