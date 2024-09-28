import java.util.ArrayList;
import java.util.Random;

public class Cache {
    private ArrayList<CacheLine> cache;

    private int CACHE_HIT;
    private int CACHE_MISS;
    private int cacheSize;
    private int lineSize;
    private int associativity;


    public int getCACHE_HIT() {
        return CACHE_HIT;
    }

    public void addCACHE_HIT() {
        CACHE_HIT++;
    }

    public int getCACHE_MISS() {
        return CACHE_MISS;
    }

    public void addCACHE_MISS() {
        CACHE_MISS++;
    }

    public ArrayList<CacheLine> getCache() {
        return cache;
    }

    public void setCache(ArrayList<CacheLine> cache) {
        this.cache = cache;
    }

    public Cache(int cacheSize, int lineSize, int associativity){
        this.CACHE_HIT = 0;
        this.CACHE_MISS = 0;
        this.cacheSize = cacheSize;
        this.lineSize = lineSize;
        this.cache = new ArrayList<CacheLine>();
        for (int i = 0; i < associativity; i++){
            cache.add(new CacheLine(i, cacheSize / associativity));
        }
        this.associativity = associativity;
    }

    public void allTimeAll(int data){
        for (CacheLine cacheLine : cache) {
            if (cacheLine.getLine().get(data % (cacheSize / associativity)) != -1) {
                cacheLine.addTime();
            }
        }
    }



    public boolean checker(int data){
        for (CacheLine cacheLine : cache) {
            if (cacheLine.getLine().get(data % (cacheSize / associativity)) != -1) {
                if (data == cacheLine.getLine().get(data % (cacheSize / associativity))) {
                    return true;
                }
            }
        }
        return false;
    }


    public void dataManipulation(int data){

        if (!checker(data)) {
            for (CacheLine cacheLine : cache) {
                if (cacheLine.getLine().get(data % (cacheSize / associativity)) == -1) {
                    this.addCACHE_MISS();
                    cacheLine.getLine().set(data % (cacheSize / associativity), data);
                    allTimeAll(data);
                    return;
                }
            }
            int time = 0;
            int num = 0;
            for (CacheLine cacheLine : cache) {
                if (cacheLine.getTime() > time) {
                    time = cacheLine.getTime();
                    num = cacheLine.getNum();
                }
            }
            this.cache.get(num).resetTime();
            this.cache.get(num).getLine().set(data % (cacheSize / associativity), data);
        }
        this.addCACHE_HIT();
        allTimeAll(data);
        return;
    }

    public static void main(String[] args) {
        Random random = new Random();
        Cache cache = new Cache(128, 16, 8);
        for (int i = 0; i < 1000; i++) {
            Integer randomNumber = random.nextInt(128) + 1; 
            System.out.println(randomNumber);
            cache.dataManipulation(randomNumber);
        }
        
        System.out.println(cache.cache.get(0).getLine().toString());
        System.out.println(cache.cache.get(1).getLine().toString());
        System.out.println(cache.cache.get(2).getLine().toString());
        System.out.println(cache.cache.get(3).getLine().toString());
        System.out.println(cache.cache.get(4).getLine().toString());
        System.out.println(cache.cache.get(5).getLine().toString());
        System.out.println(cache.cache.get(6).getLine().toString());
        System.out.println(cache.cache.get(7).getLine().toString());
        System.out.println(cache.getCACHE_HIT());
        System.out.println(cache.getCACHE_MISS());
    }
}
