class Robot {
private:
    int width, height, perimeter, pos;
    bool has_moved;

public:
    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        this->perimeter = 2 * (width - 1) + 2 * (height - 1);
        this->pos = 0;
        this->has_moved = false;
    }

    void step(int num) {
        pos = (pos + num) % perimeter;
        has_moved = true;
    }

    vector<int> getPos() {
        if (pos == 0) {
            return {0, 0};
        } else if (pos <= width - 1) {
            return {pos, 0};
        } else if (pos <= (width - 1) + (height - 1)) {
            return {width - 1, pos - (width - 1)};
        } else if (pos <= 2 * (width - 1) + (height - 1)) {
            return {(width - 1) - (pos - (width - 1) - (height - 1)),
                    height - 1};
        } else {
            return {0, (height - 1) - (pos - 2 * (width - 1) - (height - 1))};
        }
    }

    string getDir() {
        if (pos == 0) {
            return has_moved ? "South" : "East";
        } else if (pos <= width - 1) {
            return "East";
        } else if (pos <= (width - 1) + (height - 1)) {
            return "North";
        } else if (pos <= 2 * (width - 1) + (height - 1)) {
            return "West";
        } else {
            return "South";
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
