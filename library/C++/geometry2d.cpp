namespace Geometry2D{
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
        constexpr double length2() const{ return dot(*this); }
        constexpr double dot(const Point& other) const{ return x * other.x + y * other.y; }
        constexpr double cross(const Point& other) const{ return x * other.y - y * other.x; }
        double dist(const Point& other) const{ return (other - *this).length(); }
        Point normalized() const{ return *this / length(); }
        constexpr bool isZero() const{ return x == 0.0 && y == 0.0; }
        Point normalUnitVector() const{ return{ -normalized().y, normalized().x }; }
        Point rotation(double arg) const{ double cs = cos(arg), sn = sin(arg); return Point(x * cs - y * sn, x * sn + y * cs); }
        double angle() const{ return atan2(y, x); }
    };
    const Point error_val = { 123456789.123, 123456789.123 };
    int iSP(Point a, Point b, Point c){
        int flg = sgn((b - a).cross(c - a));
        if(flg == 1 || flg == -1) return flg;
        if(sgn((b - a).dot(c - b)) > 0) return 2;
        if(sgn((a - b).dot(c - a)) > 0) return -2;
        return 0;
    }
    int angleType(Point a, Point b, Point c){ double v = (a - b).dot(c - b); return sgn(v) > 0 ? 0 : (sgn(v) == 0 ? 1 : 2); }
    namespace Line2D{
        struct Line{
            Point from, to;
            Line(){ from = Point(), to = Point(); }
            Line(const Point& f, const Point& t){ from = f, to = t; }
            Line(const double a, const double b, const double c) {
                if(sgn(a) == 0 && sgn(b) == 0) assert(-1);
                if(sgn(b) == 0){ from = Point(-c / a, 0.0); to = Point(-c / a, 1.0); }
                else{ from = Point(0, -c / b); to = Point(1.0, -(a + c) / b); }
            }
            Point toVec() const{ return to - from; }
            Point toVecRev() const{ return from - to; }
        };
        typedef Line Ray;
        typedef Line Segment;
        pair<Point, bool> lineInterSection(const Line& l1, const Line& l2){
            if(sgn(l1.toVec().cross(l2.toVec())) == 0) return{ error_val, false };
            return{ l1.from + l1.toVec() * abs((l2.to - l1.from).cross(l2.toVec()) / l1.toVec().cross(l2.toVec())), true };
        }
        double distBetweenPointAndLine(const Point& p, const Line& l){ return abs(l.toVec().cross(p - l.from) / l.toVec().length()); }
        double distBetweenPointAndRay(const Point& p, const Ray& r){
            if(sgn((p - r.from).dot(r.toVec())) < 0) return r.from.dist(p);
            return abs(r.toVec().cross(p - r.from) / r.toVec().length());
        }
        double distBetweenPointAndSegment(const Point& p, const Segment& s){
            if(sgn(s.toVec().dot(p - s.from)) < 0 || sgn(s.toVecRev().dot(p - s.to)) < 0)
                return min(p.dist(s.from), p.dist(s.to));
            return distBetweenPointAndLine(p, s);
        }
        double distBetweenSegmentAndSegment(const Segment& s1, const Segment& s2){

        }
    }
}