package Rules;

public class Fact {
	private String left;
	private String right;
	private FactStatus status = FactStatus.NO_INFO;
	
	public Fact() {
		this(null, null);
	}
	
	public Fact(String left, String right) {
		this.setLeft(left);
		this.setRight(right);
	}

	public String getLeft() {
		return left;
	}

	public void setLeft(String left) {
		this.left = left;
	}

	public String getRight() {
		return right;
	}

	public void setRight(String right) {
		this.right = right;
	}

	public FactStatus getStatus() {
		return status;
	}

	public void setStatus(FactStatus status) {
		this.status = status;
	}
	
	@Override
	public String toString() {
		return String.format("%s = %s", left, right);
	}

	public enum FactStatus {
		TRUE, FALSE, NO_INFO;
	}
}
