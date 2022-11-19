import com.sun.source.tree.Tree;

import java.util.Comparator;
import java.util.NavigableSet;
import java.util.Objects;
import java.util.TreeSet;

public class ExamRoom {


    private final int n;
    private final NavigableSet<Interval> intervals;
    private final NavigableSet<Integer> occupied;

    public ExamRoom(int n) {
        this.n = n;
        occupied = new TreeSet<>();
        intervals = new TreeSet<>();
        intervals.add(new Interval(0, n-1, n));
    }

    public int seat() {
        Interval interval = intervals.pollFirst();
        if(interval.start == 0 ) {
            occupied.add(0);
            if(interval.end >= 1)
                intervals.add(new Interval(1, interval.end, n));
            return 0;
        }

        if(interval.end == n-1) {
            occupied.add(n-1);
            if(n-2 >= interval.start)
                intervals.add(new Interval(interval.start, n-2, n));
            return n - 1;
        }

        int id = interval.start + (interval.end - interval.start)/2;
        int lowerBound = interval.start;
        int upperBound = interval.end;
        occupied.add(id);
        if(id - 1 >= lowerBound)
            intervals.add(new Interval(lowerBound, id - 1, n));

        if(id + 1 <= upperBound)
            intervals.add(new Interval(id + 1, upperBound, n));

        // System.out.println(intervals);

        return id;
    }

    public void leave(int p) {
        occupied.remove(p);
        var lowerBound = occupied.lower(p);
        var upperBound = occupied.higher(p);

        if(lowerBound == null)
            lowerBound = -1;
        
        if(upperBound == null)
            upperBound = n;
        
        lowerBound++;
        upperBound--;
        intervals.remove(new Interval(lowerBound, p - 1, n));
        intervals.remove(new Interval(p + 1, upperBound, n));
        if(upperBound >= lowerBound)
            intervals.add(new Interval(lowerBound, upperBound, n));
        // System.out.println(intervals);
    }
}


class Interval implements Comparable<Interval> {
    int start;
    int end;
    int n;
    public Interval(int start, int end, int n)
    {
        this.start = start;
        this.end = end;
        this.n = n;
    }
    

    @Override
    public int compareTo(Interval o2) {
        Interval i1 = this;
        Interval i2 = o2;


        int dist1 = i1.end - i1.start;
        int dist2 = i2.end - i2.start;


        if(i1.end != n-1 && i1.start != 0)
            dist1 /=2;

        if(i2.end != n-1 && i2.start != 0)
            dist2 /=2;


        return dist1 == dist2 ? i1.start - i2.start : dist2 - dist1;
    }
    
    @Override
    public String toString()
    {
        return (this.start + " : " + this.end);
    }
}