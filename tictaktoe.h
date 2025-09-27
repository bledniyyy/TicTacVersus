#include <vector>
#include <QDebug>
#include <QMetaEnum>

enum class Player {
    X = 1,
    Y = 2
};


class Tiktaktoe {

private:
    Player player;
    int row;
    int col;
    std::vector<std::vector<int>> field;

public:
 

   


    Tiktaktoe() {
        field = std::vector<std::vector<int>>(3, std::vector<int>(3, 0));
    }

    void PointToFied (int x, int y, int player) {
        if (x < 0 || x >= 3 || y < 0 || y >= 3) {
            qDebug() << "PIZDA\n";
        }
        
        field[x][y] = player;
    }

    int CheckPoint (int x, int y) const {
        return field[x][y];
    }

    const bool CheckWin  (int player) const {
        return CheckRols(player) || CheckCols(player) || 
           CheckMainDiagonal(player) || CheckPobDiagonal(player);
    }

    bool CheckRols (int player) const {
        if (field.empty() || field.size() != 3) return false;
        for (int i = 0; i < 3; i++) {
            if (field[i].size() != 3) continue;

            if (field[i][0] == player && field[i][1] == player && field[i][2] == player) {
                qDebug() << "are you here";
                return true;
            }
        }
        return false;
    }

    bool CheckCols (int player) const {
        if (field.empty() || field.size() != 3) return false;
        for (int j = 0; j < 3; j++) {
            if (field[j].size() != 3) continue;

            if (field[0][j] == player && field[1][j] == player && field[2][j] == player) {
                qDebug() << "are you here";
                return true;
            }
        }
        return false;
    }

    bool CheckMainDiagonal (int player) const {
        if (field.empty() || field.size() != 3) return false;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (field[0][0] == player && field[1][1] == player && field[2][2] == player) {
                    return true;
                }
            }
        }
        
        return false;  
    }
    bool CheckPobDiagonal  (int player) const {
        if (field.empty() || field.size() != 3) return false;
        if (field[0][2] == player && field[1][1] == player && field[2][0] == player) {
            return true;
        }
        return false; 
    }
};

