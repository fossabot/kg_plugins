# Release Workflow

Recommended policy:

- Source code is managed in Git.
- Compiled `.aex` binaries are not committed.
- Public distribution files are attached to GitHub Releases.
- Tags use `vMAJOR.MINOR.PATCH`, for example `v0.1.0`.

## Local Release Steps

From this directory:

```powershell
git status
& "C:\Program Files\Microsoft Visual Studio\2022\Community\MSBuild\Current\Bin\amd64\MSBuild.exe" .\kg_plugins.sln /p:Configuration=Release /p:Platform=x64 /m
git tag v0.1.0
git push origin main
git push origin v0.1.0
```

Then create a GitHub Release from the tag and upload the built `.aex` file or a zip archive.

## Notes

If the plugin depends on local SDK paths, build releases locally first. GitHub Actions can be added later, but it needs the After Effects SDK available on the runner.
