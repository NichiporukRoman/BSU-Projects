package Rules;

import java.util.ArrayList;
import java.util.List;

import Rules.Fact.FactStatus;

public class Rule {
    private final List<Fact> conditions;
    private final List<Fact> conclusions;

    public Rule(List<Fact> conditions, List<Fact> conclusions) {
        this.conditions = conditions;
        this.conclusions = conclusions;
    }

    public List<Fact> getUnknownFacts() {
        List<Fact> unknownFacts = new ArrayList<>();
        for (Fact fact : conditions) {
            if (fact.getStatus() == FactStatus.NO_INFO) {
                unknownFacts.add(fact);
            } else if (fact.getStatus() == FactStatus.FALSE) {
                return null; 
            }
        }
        return unknownFacts;
    }

    public boolean checkRule(ForwardIndexer fw) {
        boolean satisfiedConditions = conditions.stream()
            .allMatch(fact -> fact.getStatus() == FactStatus.TRUE);

        conclusions.forEach(fact -> fw.satisfyFact(
            fact.getLeft(),
            fact.getRight(),
            satisfiedConditions ? FactStatus.TRUE : FactStatus.FALSE
        ));

        return satisfiedConditions;
    }

    public String getConclusion() {
        return conclusions.get(0).getRight();
    }

    @Override
    public String toString() {
        StringBuilder strB = new StringBuilder();
        rulesToStr(strB, conditions).append(" -> ");
        rulesToStr(strB, conclusions);
        return strB.toString();
    }

    private StringBuilder rulesToStr(StringBuilder strB, List<Fact> list) {
        for (int i = 0; i < list.size(); i++) {
            if (i > 0) {
                strB.append(" & ");
            }
            strB.append(list.get(i));
        }
        return strB;
    }
}