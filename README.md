# florimvrdemo

## How dynamic equirectangular layers are generated

* Independent tiler logic is produces a texture with the (optionally very complex) tiling patterns
* The tile-pattern texture is drawn as a 3D positioned plane and rendered into a FboCubeMap using the CubeMap::Mapper class (based on the DynamicCubeMapping example in the main cinder library repository).
* The CubeMap::Mapper's cubemap is converted into an equirectangular fbo (also done by the CubeMap::Mapper class)
* The equirectangular fbo's texture is used a Layer in the LayeredMaterial class
* The LayeredMaterial render multiple layers with various blending/masking options

_In summary_
* TILER --> CUBEMAPPER --> EQUIRECTANGULAR CONVERSION --> LAYERS
