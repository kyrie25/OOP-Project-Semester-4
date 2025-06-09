# Get --output file name
$Output = $args[0]
if ($null -eq $Output) {
    $Output = "app.exe"
}

$files = Get-ChildItem -Recurse -Filter *.cpp -Path .\src | ForEach-Object { "$($_.FullName)" }
g++ -fdiagnostics-color=always $files -o $Output