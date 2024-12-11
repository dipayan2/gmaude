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

# BuildOurOwn MAUDE
1. Go to `makeMAUDE`
2. Run these commands in order ` ./configure --with-yices2=yes --with-cvc4=no` , `make` , `make check`
3. The runtime is in `src/Main` named **maude**
4. Copy it to a new name `maude.mycopy` and then run `strip maude.mycopy`
5. We can now look at some of the code flow and the file access

# Run the resource stat script
1. Go to the `gmaude` folder
2. Run the script as `./runcmd.sh <dumpfile> <your commands>`
3. Sample run of the script `./runcmd.sh TraceDennis taskset -c 0 MaudeRuntime/maude.linux64 maude-npa.maude Examples_Maude-NPA/Denning-Sacco/Denning-Sacco.maude`

# Testing

1. Go to the `gmaude` folder.
2. Run `gdb --args ./makeMaude/src/Main/maude Experiments/EXPERIMENT-FILE `, where `EXPERIMENT-FILE` is a maude file with commands (`Maude/Bike/bike-test.maude`, for example).
3. Do multiple `run`.
4. Whenever an error hapens backtrack with `bt`.
5. Use `exit` to finish the debuggin session.

