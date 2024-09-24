package Rules;

import java.util.LinkedHashMap;
import java.util.Set;

public class BackwardIndexer {

    private final LinkedHashMap<String, RulesNest> index = new LinkedHashMap<>();

    public void registerRule(String right, Rule r) {
        index.computeIfAbsent(right, k -> new RulesNest()).putToNest(r);
    }

    public void clean() {
        index.values().forEach(RulesNest::clear);
    }

    public RulesNest findMatchingRules(String right) {
        return index.get(right);
    }

    public Set<String> getAvailableOptions() {
        return index.keySet();
    }
}