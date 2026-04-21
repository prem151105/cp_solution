# push_solution.ps1
# Script to safely organize and push your competitive programming solutions to GitHub.

Write-Host "Starting Git Push Process..." -ForegroundColor Cyan

# 1. First, automatically organize any files in the root folder that haven't been sorted yet!
Write-Host "Organizing any new .cpp files..." -ForegroundColor Yellow
$extensions = @("*.cpp", "*.c", "*.py", "*.java")
foreach ($ext in $extensions) {
    $newFiles = Get-ChildItem -File -Filter $ext
    if ($newFiles.Count -gt 0) {
        foreach ($file in $newFiles) {
            $name = $file.Name
            # Skip the solution file if they want to keep it in root
            if ($name -eq "solution.cpp") { continue }
            
            if ($name -match "(?i)CSES") {
                Move-Item $file.FullName -Destination "CSES\"
            } elseif ($name -match "(?i)AtCoder") {
                Move-Item $file.FullName -Destination "AtCoder\"
            } elseif ($name -match "(?i)USACO") {
                Move-Item $file.FullName -Destination "USACO\"
            } elseif ($name -match "\d{2,}[A-Za-z]?") {
                Move-Item $file.FullName -Destination "Codeforces\"
            } else {
                Move-Item $file.FullName -Destination "Others\"
            }
        }
    }
}

# 2. Add all your local changes
Write-Host "Staging files..." -ForegroundColor Yellow
git add .
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error occurred during git add." -ForegroundColor Red
    exit
}

# Check if there's anything to commit
$status = git status --porcelain
if ([string]::IsNullOrWhiteSpace($status)) {
    Write-Host "No changes to push. Everything is up to date!" -ForegroundColor Green
    exit
}

# 3. Commit with current date and time
$timestamp = Get-Date -Format "yyyy-MM-dd HH:mm:ss"
$commitMessage = "Daily Practice Update: $timestamp"

Write-Host "Creating commit: $commitMessage" -ForegroundColor Yellow
git commit -m $commitMessage
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error occurred during git commit." -ForegroundColor Red
    exit
}

# 4. Fetch remote changes safely and integrate them
Write-Host "Fetching latest updates from GitHub to prevent errors..." -ForegroundColor Yellow
git pull origin main --rebase
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error occurred during git pull. Please check for conflicts." -ForegroundColor Red
    exit
}

# 5. Push!
Write-Host "Pushing code to GitHub..." -ForegroundColor Yellow
git push origin main
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error occurred during git push." -ForegroundColor Red
    exit
}

Write-Host "Code successfully organized and pushed to GitHub! Great job today!" -ForegroundColor Green
