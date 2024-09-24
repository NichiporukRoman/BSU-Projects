package Rules;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.Set;

import Rules.Fact.FactStatus;


public class ForwardIndexer {
    private final LinkedHashMap<String, LinkedHashMap<String, Fact>> index = new LinkedHashMap<>();
    private final ArrayList<Fact> facts = new ArrayList<>();

    public Fact createRule(String left, String right) {
        LinkedHashMap<String, Fact> keys = index.computeIfAbsent(left, k -> new LinkedHashMap<>());
        return keys.computeIfAbsent(right, k -> {
            Fact newFact = new Fact(left, right);
            facts.add(newFact);
            return newFact;
        });
    }

    public Set<String> getAvailableOptions(String left) {
        if (left == null) {
            return index.keySet();
        }
        LinkedHashMap<String, Fact> options = index.get(left);
        return options != null ? options.keySet() : null;
    }

    public void satisfyFact(String left, String right, FactStatus status) {
        LinkedHashMap<String, Fact> options = index.get(left);
        if (options == null) {
            System.err.printf("Bad reference to fact: %s = %s%n", left, right);
            return;
        }

        options.forEach((key, fact) -> {
            if (status == FactStatus.TRUE) {
                fact.setStatus(key.equals(right) ? FactStatus.TRUE : FactStatus.FALSE);
            } else if (status == FactStatus.FALSE && key.equals(right)) {
                fact.setStatus(FactStatus.FALSE);
            }
        });
    }

    public void clean() {
        facts.forEach(fact -> fact.setStatus(FactStatus.NO_INFO));
    }
}