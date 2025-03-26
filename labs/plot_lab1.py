import sys
import pandas as pd
import matplotlib.pyplot as plt


def main():
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <input_csv> <output_image>")
        sys.exit(1)

    input_csv = sys.argv[1]
    output_image = sys.argv[2]

    # Load CSV (assuming no header row)
    df = pd.read_csv(input_csv, header=None)
    # Rename columns for clarity
    df.columns = ["Probability", "BER", "BER_Hamming", "BER_Custom"]

    # Create the plot
    plt.figure(figsize=(10, 6))
    plt.loglog(df["Probability"], df["BER"], marker="o", label="BER")
    plt.loglog(df["Probability"], df["BER_Hamming"], marker="s", label="BER (Hamming)")
    plt.loglog(df["Probability"], df["BER_Custom"], marker="^", label="BER (Custom)")

    plt.xlabel("Input Bit Error Probability (log scale)")
    plt.ylabel("Bit Error Rate (BER) (log scale)")
    plt.title("BER vs. Input Probability (Log-Log Scale)")
    plt.grid(True, which="both", ls="--", linewidth=0.5)
    plt.legend()

    # Invert the x-axis
    plt.gca().invert_xaxis()

    # Tight layout for cleaner look
    plt.tight_layout()

    # Save the figure
    plt.savefig(output_image, dpi=300)
    print(f"Plot saved to {output_image}")


if __name__ == "__main__":
    main()
