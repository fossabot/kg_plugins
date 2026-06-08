# kg_LayoutGrid

After Effects SDK based layout grid plugin.

## Layout

- `kg_plugins.sln` - Visual Studio solution for `kg_LayoutGrid`.
- `kg_LayoutGrid` - plugin source and Visual Studio project files.

This repository is expected to live under:

```text
AfterEffectsSDK/Examples/kg_plugins
```

The project uses relative paths to the After Effects SDK `Examples` headers and utility projects.

## Build

Open `kg_plugins.sln` with Visual Studio 2022, or build with MSBuild:

```powershell
& "C:\Program Files\Microsoft Visual Studio\2022\Community\MSBuild\Current\Bin\amd64\MSBuild.exe" .\kg_plugins.sln /p:Configuration=Release /p:Platform=x64 /m
```

Build artifacts are ignored by Git. Keep source changes in Git, and publish compiled `.aex` files through GitHub Releases.

## Release

1. Build `Release|x64`.
2. Collect the `.aex` files from the configured output directory.
3. Create a version tag:

```powershell
git tag v0.1.0
git push origin main --tags
```

4. Attach the built `.aex` files or a zip archive to the matching GitHub Release.
