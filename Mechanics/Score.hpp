#ifndef SCORE_HPP
#define SCORE_HPP

class Score {
private:
    int currentScore;
    int highScore;

public:
    Score();
    void add(int points);
    int getScore() const;
    int getHighScore() const;
    void reset();
};

#endif
