# gmaude


# Run Maude-NPA

In order to run Maude-NPA one needs to do the following steps. All of these steps were done over a LINUX distribution.

1. Download this repository, which contains **Maude 3.4**.
2. Open a terminal in the parent folder containing the downloaded files.
3. Launch Maude with `./MaudeRuntime/maude.linux64`.
4. Load the Maude-NPA file with `load maude-npa.maude`.
5. Load one of the examples in folder **Examples_Maude-NPA**.

Everything in one line: `./MaudeRuntime/maude.linux64 maude-npa.maude EXAMPLE`, where `EXAMPLE` is the path to the example (*protocol.maude* file) you want to execute.

If you want Maude to close at the end you need to make sure that at the end of the example there is a `q`.
