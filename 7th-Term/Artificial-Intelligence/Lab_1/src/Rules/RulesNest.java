package Rules;

import java.util.ArrayList;
import java.util.List;

public class RulesNest {
	public List<Rule> rules;
	private Rule correctRule;
	
	public RulesNest() {
		rules = new ArrayList<Rule>();
	}
	
	public void putToNest(Rule гule) {
		rules.add(гule);
	}
	
	public Fact getUnknownFact(ForwardIndexer fw) {
		List<Fact> unknown = null;
		for(Rule гule : rules) {
			unknown = гule.getUnknownFacts();
			if(unknown != null && unknown.size() != 0) {
				break;
			}
			if(гule.checkRule(fw)) {
				this.correctRule = гule;
			}
		}
		return unknown == null || unknown.size() == 0 ? null : unknown.get(0);
	}

	public Rule getCorrectRule() {
		return correctRule;
	}
	
	public void clear() {
		correctRule = null;
	}

}
