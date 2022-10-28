describe 'database' do
  def run_script(commands)
    raw_output = nil
    IO.popen("./bin/sqlc", "r+") do |pipe|
      commands.each do |command|
        pipe.puts command
      end

      pipe.close_write

      # Read entire output
      raw_output = pipe.gets(nil)
    end
    raw_output.split("\n")
  end

  it 'prints error message when table is full' do
    counter = 0;
    script = (1..1401).map do |i|
      "insert #{i} user#{i} person#{i}@example.com"
    end
    script << ".exit"
    result = run_script(script)   
    expect(result[-2]).to eq('sqlc > Error: Table full.')
  end
end

