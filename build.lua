--[[
    little script to compile and run C program
]]
-- Setup
local target_file = "src/main.c "
local output_name = "Iter"
local all_lib = ""
local lib_table = {
    "include/bless_tui"
}

for i=1, #lib_table do -- on parcour la table avec la boucle
    all_lib = all_lib.."-I\""..lib_table[i].."\" "
end

print("Enter the output name : ")
output_name = io.read()

-- Compilation
print("\nStarting compilation...")
local compilation_t0 = os.time()
os.execute("gcc ".. all_lib .. target_file .."-o bin/".. output_name)
local compilation_time = os.time() - compilation_t0
print("Compilation done in "..compilation_time.. " seconds.")

-- Execution
print("Starting execution... \n")
local execution_t0 = os.time()
os.execute("./bin/".. output_name)
local execution_time = os.time() - execution_t0
print("\nExecution done in "..execution_time.." seconds")