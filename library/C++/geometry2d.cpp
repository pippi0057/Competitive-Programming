namespace geometry2d{
    const double EPS = 1e-10;
    const double PI = 3.14159265358979;
    double dtor(double d){ return d * PI / 180.0; }
    double rtod(double r){ return r * 180.0 / PI; }
    int sgn(const double a){ return a < -EPS ? -1 : (a > EPS ? 1 : 0); }
    struct Point{
        double x, y;
        constexpr Point() : x(0.0), y(0.0) {}
        constexpr Point(double x, double y) : x(x), y(y) {}
        constexpr Point operator +() const{ return *this; }
        constexpr Point operator -() const{ return{ -x, -y }; }
        constexpr Point operator +(const Point& other) const{ return{ x + other.x, y + other.y }; }
        constexpr Point operator -(const Point& other) const{ return{ x - other.x, y - other.y }; }
        constexpr Point operator *(double s) const{ return{ x * s, y * s }; }
        constexpr Point operator /(double s) const{ return{ x / s, y / s }; }
        Point& operator +=(const Point& other){ x += other.x; y += other.y; return *this; }
        Point& operator -=(const Point& other){ x -= other.x; y -= other.y; return *this; }
        Point& operator *=(double s){ x *= s; y *= s; return *this; }
        Point& operator /=(double s){ x /= s; y /= s; return *this; }
        inline bool operator ==(Point other){ return x == other.x && y == other.y; }
        inline bool operator <(Point other){ if(sgn(x - other.x) == 0) return sgn(y - other.y) < 0; return sgn(x - other.x) < 0; }
        inline bool operator <=(Point other){ return *this == other || *this < other; }
        inline bool operator >(Point other){ return !(*this <= other); }
        inline bool operator >=(Point other){ return !(*this < other); }
        inline bool operator !=(Point other){ return !(*this == other); }
        double length() const{ return sqrt(max(0.0, length2())); }
        constexpr double dot(const Point& other) const{ return x * other.x + y * other.y; }
        constexpr double cross(const Point& other) const{ return x * other.y - y * other.x; }
        constexpr double length2() const{ return dot(*this); }
        double dist(const Point& other) const{ return (other - *this).length(); }
        Point normalized() const{ return *this / length(); }
        constexpr bool isZero() const{ return x == 0.0 && y == 0.0; }
        Point normalUnitVector() const{ return{ -normalized().y, normalized().x }; }
        Point rotation(double arg) const{ double cs = cos(arg), sn = sin(arg); return Point(x * cs - y * sn, x * sn + y * cs); }
        double angle() const{ return atan2(y, x); }
    };
    int iSP(Point a, Point b, Point c){
        int flg = sgn((b - a).cross(c - a));
        if(flg == 1 || flg == -1) return flg;
        if(sgn((b - a).dot(c - b)) > 0) return 2;
        if(sgn((a - b).dot(c - a)) > 0) return -2;
        return 0;
    }
    int angleType(Point a, Point b, Point c){ double v = (a - b).dot(c - b); return sgn(v) > 0 ? 0 : (sgn(v) == 0 ? 1 : 2); }
}